<?php
parse_str(implode('&', array_slice($argv, 1)), $_GET);

echo "<html>
	<body>";
echo "var1 = $argv[0] <br>";
echo "var2 = $argv[1] <br>";
echo "var3 = $argv[2] <br>";


echo "name = $_GET[name]<br>";
echo "first name = $_GET[first_name] <br>";

echo "</body>
</html>";


?>

