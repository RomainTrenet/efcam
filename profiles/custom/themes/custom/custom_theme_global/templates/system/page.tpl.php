<?php

/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $secondary_menu_heading: The title of the menu used by the secondary links.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['branding']: Items for the branding region.
 * - $page['header']: Items for the header region.
 * - $page['navigation']: Items for the navigation region.
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['footer']: Items for the footer region.
 *
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see template_process()
 * @see omega_preprocess_page()
 */
?>
<div id="fancy_container"></div>
<?php print render($title_prefix); ?>
<?php if ($title): ?>
  <h1 class="element-invisible"><?php print $title; ?></h1>
<?php endif; ?>
<?php //print render($title_suffix); ?>
<div class="l-page">
  <?php //Header ?>
	<?php print render($title_suffix); // Prints page level contextual links ?>
  <div class="l-main">
    <div class="l-content" role="main">
      <?php if(!empty($page['highlighted'])) : ?>
        <?php print render($page['highlighted']); ?>
      <?php endif; ?>
      
      <?php /* print $breadcrumb;
      <a id="main-content"></a> */ ?>
      <header class="l-content-header clearfix" id="content_header" role="banner">
		    <?php
		    //Main content header
		    print theme('custom_layout_main_content_header_theme', array(
			    //'title' => $title,
			    'image' => !empty($main_content_header_image) ? $main_content_header_image : NULL,
			    //'content' => !empty($main_content_header_content) ? $main_content_header_content : NULL,
		    ));
		    //unset($title);
		
		    //Above header
		    if (!empty($above_main_header_content)) {
		      $above_content = array();
		      if (!empty($above_main_header_content['title'])) {
			      $above_content['title'] = $above_main_header_content['title'];
          }
			    if (!empty($above_main_header_content['subtitle'])) {
				    $above_content['subtitle'] = $above_main_header_content['subtitle'];
			    }
			    print theme('custom_layout_above_main_header', $above_content);
		    }
		    ?>
      </header>
      
      <?php if (!empty($messages)) : ?>
        <div class="container-fluid container-messages">
          <div class="container-inner">
            <div class="row">
              <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12"><?php print render($messages); ?></div>
            </div>
          </div>
        </div>
      <?php endif; ?>
	
	    <?php if (!empty($tabs)) : ?>
        <div class="container-fluid container-tabs">
          <div class="container-inner">
            <div class="row">
              <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12"><?php print render($tabs); ?></div>
            </div>
          </div>
        </div>
	    <?php endif; ?>
      
      <?php print render($page['help']); ?>
      
      <?php if ($action_links): ?>
        <div class="container-fluid container-action">
          <div class="container-inner">
            <div class="row">
              <div class="col-xs-12 col-sm-12 col-md-12 col-lg-12">
                <ul class="action-links"><?php print render($action_links); ?></ul>
              </div>
            </div>
          </div>
        </div>
      <?php endif; ?>
      
      <?php print render($page['content']); ?>
      <?php print $feed_icons; ?>
    </div>

    <?php print render($page['sidebar_first']); ?>
    <?php print render($page['sidebar_second']); ?>
  </div>

  <header class="l-header" id="header" role="header"><?php //TODO check role ?>
    <div class="container-fluid">
      <div class="container-inner">
        <div class="row">
          <div class="table clearfix">
            <div class="col-branding col-md-3 col-lg-3 table-cell f-none">
							<?php
							// Branding.
							print theme('custom_layout_branding', array(
								'logo' => !empty($logo) ? $logo : NULL,
								'front_page' => !empty($front_page) ? $front_page : NULL,
								'site_name' => !empty($site_name) ? $site_name : NULL,
								'site_slogan' => !empty($site_slogan) ? $site_slogan : NULL,
							));
							?>
            </div>
            <div class="col-cta col-md-9 col-lg-9 table-cell f-none">
							<?php
							// CTAS.
							print theme('custom_layout_header_ctas', array(
								'ctas' => !empty($ctas) ? $ctas : NULL,
							));
							?>
            </div>
						<?php //print render($page['header']); ?>
						<?php //print render($page['branding']); ?>
						<?php //print render($page['navigation']); ?>
          </div>
        </div>
      </div>
    </div>
  </header>
  <div id="header_spacer" class="header-spacer"></div>

  <footer class="l-footer" role="contentinfo">
    <?php print render($page['footer']); ?>
  </footer>
</div>