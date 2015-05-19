$(nodes).serialize() // Encode a set of form eles as a string for submission
$(nodes).serializeArray() // Encode a set of form eles as an array

/**
 * @example true $.contains(document.documentElement, document.body)
 */
boolean $.contains(container, contained)

$(nodes).append("html_to_the_end_of_inner_nodes")
$(nodes).appendTo("tag_append_to_the_out_of_nodes")
$(nodes).prepend("html_to_the_begin_of_inner_nodes")
$(nodes).prependTo("tag_to_the_inner_of_inner_nodes")

// <p id="preach"></p><div class="preacher"></div>

$('p[id="preach"]').appendTo('div[id="preacher"]')
// <div class="preacher"><p id="preach"></p></div>

$('p[id="preach"]').prependTo('div[id="preacher"]')
// <p id="preach"><div class="preacher"></div></p>

// <div></div><div></div>
$('<p/>').appendTo('div')
        .addClass('judge')
        .end()
        .addClass('court');
// <div><p class="judge court"></p></div><div><p class="judge"></p></div>

$(nodes).after(html | $(nodes) | function(){})
$(nodes).before($(nodes))