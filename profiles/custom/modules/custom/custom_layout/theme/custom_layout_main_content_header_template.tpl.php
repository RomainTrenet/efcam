<div class="ec-content-header">
  <?php if(isset($title)) : ?>
    <div class="over content container-fluid">
      <h1 id="page-title"><?php print $title; ?></h1>
      <?php if(isset($content)) : ?>
        <div class="desc"><?php print $content; ?></div>
      <?php endif; ?>
    </div>
  <?php endif; ?>
  <?php if(isset($image)) : ?>
    <?php
      $variables = array(
        'style_name' => 'compress',
        'path' => $image->uri,
        'width' => $image->width,
        'height' => $image->height,
      );
      isset($image->alt) ? $variables['alt'] = $image->alt : NULL;
      isset($image->title) ? $variables['title'] = $image->title : NULL;
	  ?>
    <div class="bkgd"><?php print theme('image_style', $variables); ?></div>
  <?php endif; ?>
</div>