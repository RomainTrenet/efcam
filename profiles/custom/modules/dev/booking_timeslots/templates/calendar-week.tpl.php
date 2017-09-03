<?php
/**
 * @file
 * Template to display a view as a calendar week.
 *
 * @see template_preprocess_calendar_week.
 *
 * $day_names: An array of the day of week names for the table header.
 * $rows: The rendered data for this week.
 *
 * For each day of the week, you have:
 * $rows['date'] - the date for this day, formatted as YYYY-MM-DD.
 * $rows['datebox'] - the formatted datebox for this day.
 * $rows['empty'] - empty text for this day, if no items were found.
 * $rows['all_day'] - an array of formatted all day items.
 * $rows['items'] - an array of timed items for the day.
 * $rows['items'][$time_period]['hour'] - the formatted hour for a time period.
 * $rows['items'][$time_period]['ampm'] - the formatted ampm value, if any for a time period.
 * $rows['items'][$time_period]['values'] - An array of formatted items for a time period.
 *
 * $view: The view.
 * $min_date_formatted: The minimum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 * $max_date_formatted: The maximum date for this calendar in the format YYYY-MM-DD HH:MM:SS.
 */
// dsm('Display: '. $display_type .': '. $min_date_formatted .' to '. $max_date_formatted);
// dsm($rows);
// dsm($items);
$index = 0;
$header_ids = array();
foreach ($day_names as $key => $value) {
  $header_ids[$key] = $value['header_id'];
}
?>
<div class="bts-calndr week-view">
<table class="full">
  <thead>
    <tr>
      <?php if($by_hour_count > 0 || !empty($start_times)) :?>
      <th class="calendar-agenda-hour"><?php print t('Time')?></th>
      <?php endif;?>
      <?php //dpm($day_names); ?>
      <?php foreach ($day_names as $cell): ?>
        <th class="<?php print $cell['class']; ?>" id="<?php print $cell['header_id']; ?>">
          <?php print $cell['data']; ?>
        </th>
      <?php endforeach; ?>
    </tr>
  </thead>
  <tbody>
    <?php // Case of multidays. ?>
    <?php /* for ($i = 0; $i < $multiday_rows; $i++): ?>
      <?php
        $colpos = 0;
        $rowclass = "all-day";
        if($i == 0) {
          $rowclass .= " first";
        }
        if($i == $multiday_rows - 1) {
          $rowclass .= " last";
        }
      ?>
      <tr class="<?php print $rowclass?>">
        <?php if($i == 0 && ($by_hour_count > 0 || !empty($start_times))) :?>
        <td class="<?php print $agenda_hour_class ?>" rowspan="<?php print $multiday_rows?>">
          <span class="calendar-hour"><?php print t('All day', array(), array('context' => 'datetime'))?></span>
        </td>
        <?php endif; ?>
        <?php for($j = 0; $j < 6; $j++): ?>
          <?php $cell = (empty($all_day[$j][$i])) ? NULL : $all_day[$j][$i]; ?>
          <?php if($cell != NULL && $cell['filled'] && $cell['wday'] == $j): ?>
            <?php for($k = $colpos; $k < $cell['wday']; $k++) : ?>
            <td class="multi-day no-entry"><div class="inner">&nbsp;</div></td>
            <?php endfor;?>
            <td colspan="<?php print $cell['colspan']?>" class="multi-day">
              <div class="inner">
              <?php print $cell['entry']?>
              </div>
            </td>
            <?php $colpos = $cell['wday'] + $cell['colspan']; ?>
          <?php endif; ?>
        <?php endfor; ?>
        <?php for($j = $colpos; $j < 7; $j++) : ?>
        <td class="multi-day no-entry"><div class="inner">&nbsp;</div></td>
        <?php endfor;?>
      </tr>
    <?php endfor; ?>
    */ ?>
    
    <?php foreach ($items as $time_id => $time) : ?>
      <?php if (isset($time['hide'])) { continue; } ?>
      <?php // Create line. ?>
      <tr class="not-all-day <?php print (isset($time['tr-class'])) ? $time['tr-class'] : NULL; ?>">
        <?php // Left TD. ?>
        <td class="calendar-agenda-hour">
          <span class="calendar-hour"><?php print $time['hour']; ?></span><span class="calendar-ampm"><?php print $time['ampm']; ?></span>
        </td>
        <?php // Slots of the line. ?>
        <?php $curpos = 0; ?>
        <?php foreach ($columns as $index => $column): ?>
          <?php $colpos = (isset($time['values'][$column][0])) ? $time['values'][$column][0]['wday'] : $index; ?>
          <?php for ($i = $curpos; $i < $colpos; $i++): ?>
            <td class="item single-day">
              <div class="calendar">
                <div class="inner">&nbsp</div>
              </div>
            </td>
          <?php endfor; ?>
          <?php $curpos = $colpos + 1;?>
          
          <?php
            // Is TD visible.
            $td_visible = (@$items[$time_id]['values'][$column]['hidden'] != TRUE);
          ?>
  
          <?php if ($td_visible): ?>
		        <?php
		        /*
						EXEMPLE :
						Lundi 7 aout à 9h
		        en js :
						["11","12",null,"929","2017-08-07 09:00",30]
						WyIxMSIsIjEyIixudWxsLCI5MjkiLCIyMDE3LTA4LTA3IDA5OjAwIiwxNV0=
		        
		        en php
		        ["11","12",null,"929","2017-08-07 09:00",30]
		        WyIxMSIsIjEyIixudWxsLCI5MjkiLCIyMDE3LTA4LTA3IDA5OjAwIiwzMF0=
						
						
						Jeudi 10 à 9h
						["11","12",null,"1037","2017-08-10 09:00",30]
						WyIxMSIsIjEyIixudWxsLCIxMDM3IiwiMjAxNy0wOC0xMCAwOTowMCIsMTVd
						
						*/
		        ?>
		        <?php
              if (isset($time['values'][$column]['attributes'])) {
                // Get attributes.
                $slot_attr = $time['values'][$column]['attributes'];
                $start_time = $slot_attr['start_time'];
                $end_time = $slot_attr['end_time'];
                $regular_non_members_price = $slot_attr['data']->price->regular->non_members;
        
                // Calculate link. TODO : should be calculated outside template.
                $data_to_encode = array($slot_attr['primary_id'], $slot_attr['secondary_id'], $slot_attr['tertiary_id'], $slot_attr['cid'], $slot_attr['date'], $slot_attr['grid_granularity']);
                $temp_path = json_encode($data_to_encode);
                $temp_path = base64_encode($temp_path);
                $booking_path = "booking/add/" . $temp_path;
              }
              
              // Calculate html attributes.
              $rowspan = isset($time['values'][$column]['records'][0]['rowspan']) ? $time['values'][$column]['records'][0]['rowspan'] : NULL;
              $classes = 'item single-day' . (isset($time['values'][$column]['class']) ? ' ' . $time['values'][$column]['class'] : NULL);
		        ?>
            <td <?php if ($rowspan): ?> rowspan="<?php print $rowspan; ?>"<?php endif; ?> class="<?php print $classes; ?>" headers="<?php print $header_ids[$index] ?>">
              
              <?php if(!empty($time['values'][$column]['records'])) :?>
	              <?php
                //dpm($time['values'][$column]['records']);
	              
	              // TODO Improve the way of detecting reservation.
	              $reserved = (count($time['values'][$column]['records']) > 1);
	              ?>
                <div class="td-inner">
                  <?php if (!$reserved) : ?>
                    <span class="book"><?php print t('Available'); ?></span>
                    <div class="hover">
                      <?php
                        print l(t('Book !'), $booking_path, array(
                          'attributes' => array(
                            'class' => 'book',
                          ),
                        ));
                      ?>
                      <div class="green-box">
                        <div class="green-box-arrow-box">
                          <div class='top'></div><div class='bottom'></div>
                        </div>
                        <?php // Right info. ?>
                        <div class="green-box-info-box"><?php print (isset($start_time) ? $start_time : NULL) ; ?> - <?php print (isset($end_time) ? $end_time : NULL); ?></div>
                        <?php // Price. ?>
                        <div class="green-box-info-pay-box"><?php print (isset($regular_non_members_price) ? $regular_non_members_price : NULL) ; ?>€</div>
                      </div>
                    </div>
                  <?php else : ?>
                    <span class="book"><?php print t('Unavailable'); ?></span>
	                  <?php /* foreach($time['values'][$column]['records'] as $item) :?>
                      <div class="entry">
			                  <?php print $item['entry'] ?>
                      </div>
	                  <?php endforeach; */ ?>
	                <?php endif; ?>
                </div>
              <?php endif; ?>
            </td>
          <?php endif; ?>
        <?php endforeach; ?>
        
        <?php for ($i = $curpos; $i < 7; $i++): ?>
          <td class="item single-day">
            <div class="calendar">
              <div class="inner">&nbsp</div>
            </div>
          </td>
        <?php endfor; ?>
        
      </tr>
   <?php endforeach; ?>
  </tbody>
</table>
</div>
