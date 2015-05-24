$(nodes).ajaxStart(callback(event, request, settings))
$(nodes).ajaxError(callback(event, request, settings))
$(nodes).ajaxSend(callback(event, request, settings))
$(nodes).ajaxStop(callback(event, request, settings))
$(nodes).ajaxSuccess(callback(event, request, settings))
$(nodes).ajaxComplete(callback(event, request, settings))


$.ajaxSetup({"setting global default value of below"});
$.ajax({
    type: default 'GET' | 'POST' ,
    url:"",
    context: document.body,     // specify this
    contents:{},
    contentTypes:string default "application/x-www-form-urlencoded",
    data:{},
    dataFilter:function(data, type){},
    dataType: string "json"|"jsonp"|"text"|"xml"|"html"|"script",
    success:function(data, testStatus){},
    complete:function(XMLHttpRequest, textStatus){},
    error:function(XMLHttpRequest, textStatus, errorThrow){},
    statusCode: {
        404:function(){alert('404');}
    },
    jsonp:string "param_new", // ?callback=?  change to ?param_new=?
    jsonpCallback:,
    crossDomain: boolean default false,
    headers:{},
    accept:,
    async:,
    beforeSend:function(XMLHttpRequest){},
    cache: boolean default true,
    converters:default  {"* text": window.String, "text html": true, 
                    "text json": jQuery.parseJSON, "text xml": jQuery.parseXML},
    global:boolean default true,
    ifModified:boolean default false,   // judge from Last-Modified
    isLocal:,
    mimeType:,
    scriptCharset:,     // only for GET
    timeout: int microseconds,
    username:,
    password,
    xhr:,
    xhrFileds:,   
})

$(nodes).load("url [only_keep_this_nodes]"
                [, {jdata}]
                [, callback(response, status, XMLHttpRequest)])
$("").load('.php', function(response, status, XMLHttpRequest){
    if(status == "error"){
        $("#err").html(XMLHttpRequest.status + xhr.statusText);
    }
});
$.ajax().done(function(){})
        .fail(function(){});

/**
 * @param string event [click | submit]
 * @note using it to replace .bind(), 使用 on() 方法的事件处理程序适用于当前或未来的元素（比如由脚本创建的新元素）
 */
$(nodes).on(events[, child_selector] [, arg_of_fn], function(){})
$(nodes).one(events[, child_selector] [, arg_of_fn], function(){})

/**
 * Remove events on $('nodes').on()
 */
$(nodes).off(events[, selector][, fn])

// 取消form表单提交或a打开的超连接
event.preventDefault();
// 同样也支持取消(A)事件冒泡
event.stopPropagation();


$('nodes').show([int speed_microsec][, "swing" | "linear"][, fn(){}])
$('nodes').hide([int speed_microsec][, "swing" | "linear"][, fn(){}])

/**
 * click between 2 or more selectors
 */
$('nodes').toggle([int speed_microsec][, "swing" | "linear"][, fn(){}])
$('nodes').toggle(fn_1st_click(), fn_2nd_click(), fn_3rd_click() ...)

$('nodes').slideUp([int speed_microsec][, esing="swing"|"linear"][, fn()])
$('nodes').slideDown([int speed_microsec][, esing="swing"|"linear"][, fn()])
$('nodes').slideToggle([int speed_microsec][, esing="swing"|"linear"][, fn()])

$('nodes').fadeIn([int speed_microsec][, easing="swing"|"linear"][, fn()])
$('nodes').fadeOut([int speed_microsec][, easing="swing"|"linear"][, fn()])
$('nodes').fadeToggle([int speed_microsec][, easing="swing"|"linear"][, fn()])
$('nodes').fadeTo([int speed_microsec][, float opacity][, easing][, fn()])

$('nodes').animate({params}[, int speed_microsec][, easing][, fn()])
$('#occupy').animate({
        width: "40%",
        fontSize: "25px",
        borderWidth: 10
    },
    1000, "swing", function(){}
);

$('#occupy').stop();        /* stop animation */

$('nodes').slideUp(300).delay(800).fadeIn(400);



$(function($){});            $(document).ready(function(){});









