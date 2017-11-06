(function() {
  $(document).ready(function() {
    var animate, item, items, mobile, _i, _len;
    $(".nav ul li a").click(function() {
      return $('html, body').animate({
        scrollTop: $("#" + ($(this).attr('class'))).offset().top
      }, 1500);
    });
    $(".chevron .down").click(function() {
      return $('html, body').animate({
        scrollTop: $("#about").offset().top
      }, 1500);
    });
    mobile = /Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent);
    // if ($("html").hasClass("cssanimations") && !mobile) {
    //   animate = function(animation) {
    //     return $(animation[0]).addClass("concealed").viewportChecker({
    //       classToAdd: "visible animated " + (animation[1].trim()),
    //       offset: 200
    //     });
    //   };
    //   items = [['#about p', 'fadeInUp'], ['.column', 'fadeInUp'], ['.item', 'fadeInDown'], ['.bar', 'fadeInRight'], ['.paperplane', 'bounceInDown'], ['#quote .container', 'fadeIn'], ['#quote .icon', 'fadeInDown']];
    //   for (_i = 0, _len = items.length; _i < _len; _i++) {
    //     item = items[_i];
    //     animate(item);
    //   }
    // }
    return $("#footer ul li").hover(function() {
      return $(this).find('p').stop(true, true).fadeIn(800);
    }, function() {
      return $(this).find('p').stop(true, true).fadeOut(800);
    });
  });

}).call(this);
