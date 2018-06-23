<?php
	$rows = query("SELECT * FROM history WHERE id = ?", $_SESSION["id"]);

	


	$positions = [];
	foreach ($rows as $row)
	{
		$stock = lookup($row["symbol"]);
		if ($stock !== false)
    		{
        		$positions[] = [
            		"transaction" => $row["transaction"],
			"time" => $row["time"],
            		"price" => $stock["price"],
            		"shares" => $row["shares"],
            		"symbol" => $row["symbol"]
        		];
    		}
	}

?>

<div>
	
<table align= "center", border = "1">
	<thead>
        <tr>
            <th>Transaction</th>
            <th>Date & Time</th>
            <th>Symbol</th>
            <th>Shares</th>
	    <th>Price</th>
        </tr>
    </thead>


        <?php foreach ($positions as $position): ?>

    <tr>
	<td><?= $position["transaction"] ?></td>
	<td><?= $position["time"] ?></td>
        <td><?= $position["symbol"] ?></td>
        <td><?= $position["shares"] ?></td>
        <td><?= number_format($position["price"] * $position["shares"], 2, '.', ',' ) ?></td>
    </tr>
	<?php endforeach ?>
</table>
</div>
<div>
    <a href="logout.php">Log Out</a>
</div>
