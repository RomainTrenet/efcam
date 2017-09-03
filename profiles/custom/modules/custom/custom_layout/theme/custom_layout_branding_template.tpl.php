<?php if (isset($logo) && isset($front_page) && isset($site_name)) : ?>
	<a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>"></a>

    <?php if(drupal_is_front_page()) : ?>
      <h1 class="site-name"><img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" class="site-logo" /></h1>
    <?php else : ?>
      <a class="site-name" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><img src="<?php print $logo; ?>" alt="<?php print $site_name; ?>" class="site-logo" /></a>
    <?php endif; ?>
<?php endif; ?>

<?php if ($site_slogan): ?>
  <h2 class="site-slogan"><?php print $site_slogan; ?></h2>
<?php endif; ?>