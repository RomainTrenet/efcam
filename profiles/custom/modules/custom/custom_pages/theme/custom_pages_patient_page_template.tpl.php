<div class="section section-highlighted">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
        <div class="infos col-xs-12 col-sm-12 col-md-8 col-lg-8 col-md-offset-2 col-lg-offset-2">
          <?php if (!empty($section_highlight['title'])) : ?>
            <h1><?php print $section_highlight['title']; ?></h1>
          <?php endif; ?>
          <?php if (!empty($section_highlight['body'])) : ?>
            <?php print $section_highlight['body']; ?>
          <?php endif; ?>
          <?php if (!empty($section_highlight['link_title'])) : ?>
            <?php
            $cta = [
              'text' => $section_highlight['link_title'],
	            'path' => '<front>',
              'options' => [
                'attributes' => [
                  'class' => [
                    'btn', 'scnd-btn',
                  ]
                ],
                'fragment' => 'section_first',
              ]
            ];
            print l($cta['text'], $cta['path'], $cta['options']);
            ?>
          <?php endif; ?>
        </div>
      </div>
    </div>
  </div>
</div>

<a name="section_first"></a>
<div class="section section-first section-curve section-scnd-bkgd-color section-btn-final">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
        <?php if (!empty($first_section['title'])) : ?>
          <div class="title f-right col-xs-12 col-sm-12 col-md-6 col-lg-6">
              <h1><?php print $first_section['title']; ?></h1>
          </div>
        <?php endif; ?>
        
        <?php if(isset($first_section['image'])) : ?>
          <div class="visu visu-rouded visu-bottom-shadow col-xs-12 col-sm-12 col-md-6 col-lg-6">
            <?php
              $image = $first_section['image'];
              $variables = array(
                'style_name' => 'compress',
                'path' => $image->uri,
                'width' => $image->width,
                'height' => $image->height,
              );
              isset($image->alt) ? $variables['alt'] = $image->alt : NULL;
              isset($image->title) ? $variables['title'] = $image->title : NULL;
	          ?>
            <div class="visu-wrapper"><?php print theme('image_style', $variables); ?></div>
          </div>
        <?php endif; ?>
    
        <?php if (!empty($first_section['body'])) : ?>
          <div class="infos f-right col-xs-12 col-sm-12 col-md-6 col-lg-6">
            <?php print $first_section['body']; ?>
          </div>
        <?php endif; ?>
        
        <?php if (!empty($first_section['link_title'])) : ?>
          <?php
          $cta = [
            'text' => $first_section['link_title'],
            'path' => '',
            'options' => [
              'attributes' => [
                'class' => [
                  'btn', 'main-btn',
                ]
              ]
            ]
          ];
          ?>
	        <?php
	        $form = drupal_get_form('ajax_user_login_link_form');
	        //print render($form);
	        $form['ajaxified_link']['#title'] = $first_section['link_title'];
	        $form['ajaxified_link']['#attributes']['class'][] = 'main-btn';
	        $form['ajaxified_link']['#attributes']['class'][] = 'booking';
	        ?>
          <div class="btn-wrapper"><?php print render($form);//print l($cta['text'], $cta['path'], $cta['options']); ?></div>
        <?php endif; ?>
        
      </div>
    </div>
  </div>
</div>

<div class="section section-second section-btwn-curve section-visu-bottom-right">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
	      <?php if (!empty($second_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-6 col-lg-6 col-md-offset-1 col-lg-offset-1">
            <h1><?php print $second_section['title']; ?></h1>
          </div>
	      <?php endif; ?>
	      <?php if (!empty($second_section['body'])) : ?>
          <div class="infos col-xs-12 col-sm-12 col-md-6 col-lg-6 col-md-offset-1 col-lg-offset-1">
			      <?php print $second_section['body']; ?>
          </div>
	      <?php endif; ?>
	      <?php if(isset($second_section['image'])) : ?>
          <div class="visu visu-bottom-right col-xs-12 col-sm-12 col-md-5 col-lg-5">
			      <?php
			      $image = $second_section['image'];
			      $variables = array(
				      'style_name' => 'compress',
				      'path' => $image->uri,
				      'width' => $image->width,
				      'height' => $image->height,
			      );
			      isset($image->alt) ? $variables['alt'] = $image->alt : NULL;
			      isset($image->title) ? $variables['title'] = $image->title : NULL;
			      ?>
            <div class="visu-wrapper"><?php print theme('image_style', $variables); ?></div>
          </div>
	      <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<div class="section section-third section-curve section-visus-cosmic section-main-bkgd-color">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
	      <?php if (!empty($third_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-6 col-md-offset-6 col-lg-6 col-lg-offset-6">
            <h1><?php print $third_section['title']; ?></h1>
          </div>
	      <?php endif; ?>
	      <?php if(isset($third_section['first_image']) || isset($third_section['second_image'])) : ?>
          <div class="visus visus-cosmic col-xs-12 col-sm-12 col-md-5 col-lg-5">
            <div class="visus-inner">
              <?php if(isset($third_section['first_image'])) : ?>
                <div class="visu first visu-rouded visu-top-shadow">
                  <?php
                    $image = $third_section['first_image'];
                    $variables = array(
                      'style_name' => 'compress',
                      'path' => $image->uri,
                      'width' => $image->width,
                      'height' => $image->height,
                    );
                    isset($image->alt) ? $variables['alt'] = $image->alt : NULL;
                    isset($image->title) ? $variables['title'] = $image->title : NULL;
                  ?>
                  <div class="visu-wrapper"><?php print theme('image_style', $variables); ?></div>
                </div>
              <?php endif; ?>
              <?php if(isset($third_section['second_image'])) : ?>
                <div class="visu second visu-rouded visu-top-shadow">
                  <?php
                    $image = $third_section['second_image'];
                    $variables = array(
                      'style_name' => 'compress',
                      'path' => $image->uri,
                      'width' => $image->width,
                      'height' => $image->height,
                    );
                    isset($image->alt) ? $variables['alt'] = $image->alt : NULL;
                    isset($image->title) ? $variables['title'] = $image->title : NULL;
                  ?>
                  <div class="visu-wrapper"><?php print theme('image_style', $variables); ?></div>
                </div>
              <?php endif; ?>
            </div>
          </div>
	      <?php endif; ?>
	      <?php if (!empty($third_section['body'])) : ?>
          <div class="infos col-xs-12 col-sm-12 col-md-6 col-md-offset-6 col-lg-6 col-lg-offset-6">
			      <?php print $third_section['body']; ?>
          </div>
	      <?php endif; ?>
      </div>
    </div>
  </div>
</div>

<div class="section section-fourth section-bottom">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
	      <?php if (!empty($fourth_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-12 col-lg-12">
            <h1><?php print $fourth_section['title']; ?></h1>
          </div>
	      <?php endif; ?>
        <div class="map col-xs-12 col-sm-12 col-md-7 col-md-offset-1 f-right-md col-lg-7 col-lg-offset-1 f-right-lg">
          <div class="map-wrapper">
            <div class="map-inner">
              <?php
              // Map
              $address = $thoroughfare;
              isset($premise) ? $address .= ' ' . $premise : NULL;
              $address .= ' ' . $postal_code . ' ' . $locality;
              
              $map = _custom_base_get_default_map($address, $address, $width = 460, $height = 230, $label_display = 'hidden');
              ?>
              <div id="office_map"><?php print drupal_render($map); ?></div>
            </div>
          </div>
          <div class="map-infos">
            <div class="vcard">
              <p class="fn"><a class="url" href="#"><?php print variable_get('site_name'); ?></a></p>
              <p class="adr">
                <span class="street-address"><?php print $thoroughfare; ?></span><br>
                <span class="postal-code"><?php print $postal_code; ?></span>
                <span class="region"><?php print $locality; ?></span><br>
                <span class="country-name"><?php print $country; ?></span>
              </p>
              <p class="tel"><?php print $phone; ?></p>
            </div>
          </div>
        </div>
	      <?php if (!empty($fourth_section['body'])) : ?>
          <div class="infos col-xs-12 col-sm-12 col-md-3 col-lg-3 col-md-offset-1 col-lg-offset-1">
			      <?php print $fourth_section['body']; ?>
          </div>
	      <?php endif; ?>
      </div>
    </div>
  </div>
</div>