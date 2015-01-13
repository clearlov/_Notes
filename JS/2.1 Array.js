/**
 * Array.prototype.sort(sort_func = NULL)
 *@return sorted array
 * each a b, a < b ==> a,b   a = b  a > b ==> b,a
 */

 // function queue(a,b){return a-b}
function queue(){return arguments[0] - arguments[1];}
function reverse(){return -(arguments[0] - arguments[1]);}
function parity(a,b){return a%2 ? 1 : (b%2)}
var a = b = c = d = [3,1,2,4,5,9,2,0,8,2,7,6,8];
a.sort();  // 1 2 3 4
b.sort(queue);   	// 1 2 3 4
c.sort(reverse);	// 4 3 2 1
d.sort(pairty);		// 3 1 2 4



/**
 * Array.prototype.slice(arr_start, [arr_end])
 *@param arr_start: 0=first element; -1=last element
 *@param optional arr_end: NULL=last element; -1=to last(not included)
 */
var victim = ['syphilis', 'starvation', 'rash'];
var plague = new Array(2);
plague = victim.slice(1); // ['starvation', 'rash']
document.write(plague);   // starvation,rash

/**
 * Array.prototype.concat(array_a, array_b...)
 *@param what if it's not anarray, turns to [array_a] ...
 *@return new array
 */
var mute = ['mut'];
var insanity = 'inflammation';
var lethe = ['livestock'];
mute.concat(insanity); // ['mut','inflammation']
mute.concat(lethe); // ['mut', 'inflammation', 'livestock']

/**
 * Array.prototype.join(separator = ',')
 * separator = ',', alias to Array.prototype.toString()
 */
var insomnia = ['lesion', 'lethe'];
insomnia.join(' ');  // lession lethe
insomnia.toString(); // lession,lethe

/**
 * Array.prototype.pop()
 *@return last element
 */
var irritate = ['irrational', 'infect', 'hyper'];
irritate.pop();  // hyper ->> irritate = ['irrational', 'infect'];

/**
 * Array.prototype.shift()
 *@return first element
 */
var evolve = ['greatly', 'slightly', 'fatally'];
evolve.shift(); // greatly, evolve = ['slightly', 'fatally']

/**
 * Array.prototype.unshift(elem_a, elem_b...)
 *@return new length
 */
var diarrhoea = ['dysentery'];
diarrhea.unshift('burst', 'dehydration'); 
// 4 ->> diarrhoea=['burst', 'dehydration','dysentery'] 


/**
 * Array.prototype.push(elem_a, elem_b...)
 *@return new length
 */
var humidity = ['humid'];
var len = humidity.push('heat up');  // 2 ->> humidity=['humid', 'heat up']
 
/**
 * Array.prototype.reverse()
 */
var hygiene = ['hypoxia', 'infectivity', 'inflam'];
hygiene.reverse(); // hygiene = ['inflam', 'infectivity', 'hypoxia'];
 
 
 
 
 
 
 
 
 
 
 
 
 
 