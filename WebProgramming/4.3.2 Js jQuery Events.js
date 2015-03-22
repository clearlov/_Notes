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


/**
 * @arg string event [click | submit]
 */
$('nodes').on("event", function(){})
/**
 * Only first event
 */
$('nodes').one('event', function(){})
$('nodes').bind("events_delimited_by_space", function(){})
$('nodes').unbind()

$('p').bind('mouseenter mouseleave', function(){});
$('p').bind({
    mouseenter:function(){},
    mouseleave:function(){},
})

/**
 * Remove events on $('nodes').on()
 */
$('nodes').off(["events_delimited_by_space"])




$('nodes').show([int speed_microsec][, "swing" | "linear"][, fn(){}])
$('nodes').hide([int speed_microsec][, "swing" | "linear"][, fn(){}])

/**
 * click between 2 or more selectors
 */
$('nodes').toggle([int speed_microsec][, "swing" | "linear"][, fn(){}])
$('nodes').toggle(fn_1st_click(), fn_2nd_click(), fn_3rd_click() ...)

$(function($){});            $(document).ready(function(){});









