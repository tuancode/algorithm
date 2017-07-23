<?php

/**
 * Search number from an integer list by applying Binary Search Algorithm.
 *
 * @param  int   $needle   The number to search for
 * @param  array $haystack The list to search in
 * @return int   Position of needle in list if found, otherwise -1.
*/
function binarySearch(int $needle, array $haystack): int
{
    $low = 0;
    $high = count($haystack) - 1;

    while ($low <= $high) {
        $mid = intval(($low + $high) / 2);
        $guess = $haystack[$mid];
        if ($guess == $needle) {
            return $mid;
        } elseif ($guess < $needle) {
            $low = $mid + 1;
        } elseif ($guess > $needle) {
            $high = $mid - 1;
        }
    }

    return -1;
}

$num = rtrim(fgets(STDIN));
$stackInput = explode(' ', rtrim(fgets(STDIN)));
$haystack = array_slice($stackInput, 0, $num);
$needle = rtrim(fgets(STDIN));

$result = binarySearch($needle, $haystack);
echo 'result: ';
echo ($result != -1) ? $result : 'none';
echo "\n";
