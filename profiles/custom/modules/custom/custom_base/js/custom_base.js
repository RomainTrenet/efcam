(function ($) {

    // Generic fancy box.
    $.fn.custom_base_fancy_box = function(fancy_id) {
        var $fancy_params = {
            autoSize: false,//set size in css, with .fancybox-wrap
            autoResize: true,
            nextClick: false,
            loop: false,
            height: 'auto',
            scrolling : 'auto',
            //Set id to your popup in 'wrap' element
            tpl: {
                wrap     : '<div id="' + fancy_id + '" class="fancybox-wrap" tabIndex="-1"><div class="fancybox-skin"><div class="fancybox-outer"><div class="fancybox-inner"></div></div></div></div>',
                image    : '<img class="fancybox-image" src="{href}" alt="" />',
                iframe   : '<iframe id="fancybox-frame{rnd}" name="fancybox-frame{rnd}" class="fancybox-iframe" frameborder="0" vspace="0" hspace="0"' + ($.browser.msie ? ' allowtransparency="true"' : '') + '></iframe>',
                error    : '<p class="fancybox-error">The requested content cannot be loaded.<br/>Please try again later.</p>',
                closeBtn : '<a title="Close" class="fancybox-item icon-close" href="javascript:;"></a>',
                next     : '<a title="Next" class="fancybox-nav fancybox-next" href="javascript:;"><span></span></a>',
                prev     : '<a title="Previous" class="fancybox-nav fancybox-prev" href="javascript:;"><span></span></a>'
            }
        };
        $.fancybox.open(['#fancy_container'], $fancy_params);
    };

})(jQuery);