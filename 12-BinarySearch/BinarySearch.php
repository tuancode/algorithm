<?php
function binarySearch(string $needle, array $haystack) {
    $low = 0;
    $high = count($haystack) - 1;

    while ($low <= $high) {
        $mid = round(($low + $high) / 2);
        $guess = $haystack[$mid];

        if ($guess == $needle) {
            return $mid;
        } elseif ($guess < $needle) {
            $low = $mid + 1;
        } elseif ($guess > $needle) {
            $high = $mid - 1;
        }
    }
    return 'none';
}

$handle = fopen("php://stdin", "r");
$haystack = explode(' ', trim(fgets($handle)));
$needle = trim(fgets($handle));

echo 'result: ' . binarySearch($needle, $haystack);
echo "\n";

fclose($handle);
?>
