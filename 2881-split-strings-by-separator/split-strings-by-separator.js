/**
 * @param {string[]} words
 * @param {character} separator
 * @return {string[]}
 */
var splitWordsBySeparator = function(words, separator) {
    return words.flatMap(word => word.split(separator).filter(sep_word => sep_word.length > 0));
};