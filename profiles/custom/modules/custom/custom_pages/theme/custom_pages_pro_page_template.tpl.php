<div class="section section-highlighted">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
        <div class="infos col-xs-12 col-sm-12 col-md-6 col-lg-6 col-md-offset-3 col-lg-offset-3">
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
							'path' => current_path(),
							'options' => [
								'attributes' => [
									'class' => [
										'btn', 'third-btn'
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


<div id="section_first" class="section section-first section-curve section-visu-centered section-thrd-bkgd-color section-btn-final">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
				<?php if (!empty($first_section['title'])) : ?>
          <div class="title f-right col-xs-12 col-sm-12 col-md-6 col-md-offset-6 col-lg-6 col-lg-offset-6">
            <h1><?php print $first_section['title']; ?></h1>
          </div>
				<?php endif; ?>
				
				<?php if (isset($first_section['image'])) : ?>
          <div class="visu-centered col-xs-12 col-sm-12 col-md-6 col-lg-6">
            <div class="visu-inner">
              <div class="visu visu-rouded">
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
            </div>
          </div>
				<?php endif; ?>
				
				<?php if (!empty($first_section['body'])) : ?>
          <div class="infos f-right col-xs-12 col-sm-12 col-md-6 col-md-offset-6 col-lg-6 col-lg-offset-6">
						<?php print $first_section['body']; ?>
          </div>
				<?php endif; ?>
				<?php if (!empty($first_section['link_title'])) : ?>
					<?php
					$cta = [
						'text' => $first_section['link_title'],
						'path' => current_path(),
						'options' => [
							'attributes' => [
								'class' => [
									'btn', 'scnd-btn'
								]
							],
							'fragment' => 'section_fourth',
						]
					];
					?>
          <div class="btn-wrapper"><?php print l($cta['text'], $cta['path'], $cta['options']); ?></div>
				<?php endif; ?>
      </div>
    </div>
  </div>
</div>

<div id="section_second" class="section section-second section-btwn-curve section-visus-cosmic-2">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
				<?php if (!empty($second_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-5 col-lg-5">
            <h1><?php print $second_section['title']; ?></h1>
          </div>
				<?php endif; ?>
				<?php if (isset($second_section['first_image']) || isset($second_section['second_image'])) : ?>
          <div class="visus visus-cosmic col-xs-12 col-sm-12 col-md-6 col-md-push-6 col-lg-6 col-lg-push-6">
            <div class="visus-inner">
							<?php if (isset($second_section['first_image'])) : ?>
                <div class="visu first visu-rouded">
									<?php
									$image = $second_section['first_image'];
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
							<?php if (isset($second_section['second_image'])) : ?>
                <div class="visu second visu-rouded">
									<?php
									$image = $second_section['second_image'];
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
				<?php if (!empty($second_section['body'])) : ?>
          <div class="infos col-xs-12 col-sm-12 col-md-5 col-lg-5">
						<?php print $second_section['body']; ?>
          </div>
				<?php endif; ?>
				<?php //TODO ?>
				<?php
				$cta = [
					'text' => 'Découvrez le programme',
					'path' => current_path(),
					'options' => [
						'attributes' => [
							'class' => [
								'btn', 'fourth-btn'
							]
						],
						'fragment' => 'section_third',
					]
				];
				?>
        <div
            class="btn-wrapper col-xs-12 col-sm-12 col-md-5 col-lg-5"><?php print l($cta['text'], $cta['path'], $cta['options']); ?></div>
      </div>
    </div>
  </div>
</div>

<div id="section_third" class="section section-third section-curve section-visu-centered section-thrd-bkgd-color">
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
				<?php if (!empty($third_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-6 col-md-offset-6 col-lg-6 col-lg-offset-6">
            <h1><?php print $third_section['title']; ?></h1>
          </div>
				<?php endif; ?>
				<?php if (isset($third_section['image'])) : ?>
          <div class="visu-centered col-xs-12 col-sm-12 col-md-5 col-lg-5">
            <div class="visu-inner">
              <div class="visu visu-rouded">
								<?php
								$image = $third_section['image'];
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

<div id="section_fourth" class="section section-fourth section-bottom">
  <a name="section_fourth"></a>
  <div class="container-wrapper container-fluid clearfix">
    <div class="container-inner">
      <div class="row">
				<?php if (!empty($fourth_section['title'])) : ?>
          <div class="title col-xs-12 col-sm-12 col-md-12 col-lg-12">
            <h1><?php print $fourth_section['title']; ?></h1>
          </div>
				<?php endif; ?>
				<?php if (!empty($fourth_section['body'])) : ?>
          <div class="infos col-xs-12 col-sm-10 col-sm-offset-1 col-md-10 col-md-offset-1 col-lg-10 col-lg-offset-1">
						<?php print $fourth_section['body']; ?>
          </div>
				<?php endif; ?>
				<?php if (!empty($webform)) : ?>
          <div class="contact-form col-xs-12 col-sm-8 col-sm-offset-2 col-md-6 col-md-offset-3 col-lg-6 col-lg-offset-3">
						<?php print $webform; ?>
          </div>
				<?php endif; ?>
      </div>
    </div>
  </div>
</div>