/**
 * @param {string[]} words
 * @param {character} separator
 * @return {string[]}
 */
var splitWordsBySeparator = function(words, separator) {
    let result = [];
    for (let word of words) {
        let temp = word.split(separator);
        for(let sep_word of temp) {
            if(sep_word.length > 0) {
            result.push(sep_word);

            }
        }
    }
    return result;
};