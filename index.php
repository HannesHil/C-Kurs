<?php
$fp = fopen('IP-LIST.txt', 'a');
fwrite($fp, date("H:i:s | j-M-Y, l - - "));
fwrite($fp, filter_input(INPUT_SERVER, 'REMOTE_ADDR') . " - - ");
fwrite($fp, filter_input(INPUT_SERVER, 'HTTP_USER_AGENT') . " - - ");
fwrite($fp, filter_input(INPUT_SERVER, 'PHP_SELF') . "\n");
fclose($fp);
$fp = fopen('IP-Zaehler.txt', 'a+');
$text =fgets($fp);
$zahl = intval($text);
$zahl = $zahl+1;
fclose($fp);
$fp = fopen('IP-Zaehler.txt', 'w+');
fwrite($fp,  strval($zahl));
fclose($fp);
?>


<html>
<head>
<link rel="stylesheet" href="cs.css">
<title>Folien und Aufgaben!</title>
</head>
<body>
<table id="tablee" >
<tr>
<th>
<div class="Test" id="links">
<a href="/slides/">Folien</a>
</div>
</th>
<th>
<div class="Test" id="rechts">
<a href="/exersise">Aufgaben</a>
</div>
</th>
</tr>
</table>
</body>
</html>
