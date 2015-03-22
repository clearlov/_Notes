$('nodes').each(function([i, this]){        // this
    return false;  // breaks the each, exit the each 
    return true;  // continues the next loop
});





/**
 *  :first :last :not(sel) :even :odd :eq(index) :gt(index) :lt(index) :header 
 *  :animated :focus :contains(text) :empty :has(sel) :parent :hidden :visible
 *  :nth-child(number) :first-child :last-child :only-child
 *  :enabled :disabled :checked :selected
 *   $(":input") <input> <textarea> <select> <button>
 *   $(":text")  <input type="text">
 *   $(":password")  <input type="password">
 *   $(":radio") $(":checkbox") $(":submit") $(":image") $(":reset") $(":button")
 *   $(":file")
 */
$('prev,next,next,next...') $('div,p,a')
$('prev + next')            $('div + p') // <p> must next to <div>
$('ancestor descendant')       // childs and sub-childs
$('parent > child')            // only first level, sub-childs are not included
$('prev ~ siblings')        $('div ~ p')   // all the <div> & <p> in the same level
$('nodes')[n] / $(nodes).get(n)  / $(nodes).eq(n)       // get the n node

$("nodes").add("nodes")

$("nodes").filter(nodes | function(){})
$("nodes").children(["nodes"])    $("nodes").parent(["nodes"])
$("nodes").find("nodes")    $('nodes').contents().find('nodes')
$("nodes").next(["nodes"])        
$("nodes").prevUntil(["nodes"])        $("nodes").prev(["nodes"])
$("nodes").siblings(["nodes"])


$('node[attr="val"]')
$('node[attr!="val"]')
$('node[attr^="start_with_segment"]')        $('a[class^="t-"]')
$('node[attr$="end_with_segment"]')          $('a[class$="-a"]')
$('node[attr*="segment"]')                $('input[name*="s-"]')
$('node[attr~="word_delimited_by_spaces"]')  $('a[class~="justness"]')
$('node[attrSel1][attrSel2][attrSel3]')      $('input[name][class="diary"]')

$("nodes").data("data-attr"[, "val"])
$("nodes").removeData('data-attr')

$("nodes").size() / $("nodes").length          // count the number of the nodes


$("nodes").attr('attr"[, "val"]')          
$("nodes").removeAttr('attr');
$("nodes").attr("title", function(){return this.src})
$("nodes").attr({src:"accent.jpg", alt="accent"})

$("nodes").css("style"[,"val"])
$("nodes").css({color:"#ff0", font-size:"14px"})

$("nodes").addClass("vals_dilimited_by_spaces")
$("nodes").hasClass("vals_dilimited_by_spaces")
$("nodes").removeClass(["vals_dilimited_by_spaces"]) // if NULL args, remove all

$("nodes").toggleClass("vals")        // if exists, remove; else add
var fester = 0;
$('p').click(function(){
    $(this).toggleClass("twinkle", ++fester %2 == 0);
});
$("nodes").toggleClass(function(){return "vals"});

/**
 * @return {left: int, top: int}
 */
json $("nodes").offset()                  json $("nodes").position()
$("nodes").scrollTop([int val])           $("nodes").scrollLeft([int val])
$("nodes").height([int val])              $("nodes").width([int val])
/**
 * Padding and border are not included
 */
int $("nodes").innerHeight()              int $("nodes").innerWidth()
/**
 * Padding included, if border=true, border included; default not include border
 */
int $("nodes").outerHeight([bool border=false]) 
int $("nodes").outerWidth([bool border=false])


$("nodes").val(["val"])                   $("nodes").html(["val"])
$("nodes").text(["val"])      // replace html tags to codes




