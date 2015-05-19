/**
 * Callback
 */
var testis = function(){}
$.Callback().add(testis);
boolean $.Callback().has(testis);
$.Callback().fire('testis');
$.Callback().disable();

/**
 * @return boolean | number | string | function | array | data | regexp
 */
mixed $.type(mixed)
isArray()  isFunction()  isEmptyObject() isNumeric() isPlainObject() isWindow()

json $.parseJson(string json_str);
$.each(mixed arr_or_json, function(i, o){})
$.extend(mixed arr_or_json[,mixed arr_or_json[,..]])
array $.merge(arr, arr);
$.grep(mixed arr_or_json, function(i, o){return bool_for_keep});
$.map(mixed arr_or_json, function(i, o){do something to each element of arr_or_json});
$.makeArray(mixed arr_or_json)

/**
 * @return >0 on first index; -1 on not find
 */
int $.inArray(mixed val, arr[, int fromIndex])
$.unique(arr)


$.param(mixed arr_or_json[, bool trandition])
decodeURIComponent

$.error = console.error;

