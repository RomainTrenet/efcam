<?php if (isset($ctas) && is_array($ctas)): ?>
  <?php if (count($ctas) > 0 ) : ?>
    <div class="ctas f-right-sm f-right-md f-right-lg">
        <ul>
        <?php foreach ($ctas as $id => $cta) : ?>
          <li><?php print l($cta['text'], $cta['path'], $cta['options']); ?></li>
        <?php endforeach; ?>
      </ul>
    </div>
  <?php endif; ?>
<?php endif; ?>