<?php require_once("../public/quote.php");
$stock = lookup($_POST["symbol"]); ?>

<form action="quote.php" method="get">
	<div id="quote">
		<p>
			<?php print("Price: " . number_format($stock["price"], 2, '.',',')); ?>
		</p>
	</div>
</form>
