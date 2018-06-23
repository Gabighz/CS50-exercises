<?php
	require("../includes/config.php");

        $rows = query("SELECT * FROM Portfolio WHERE id = ?", $_SESSION["id"]);
	$stock["name"] = query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);
	$userinfo = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
	$cash = $userinfo[0]["cash"];
	
	
	
	

	$positions = [];
	foreach ($rows as $row)
	{
		$stock = lookup($row["symbol"]);
		if ($stock !== false)
    		{
        		$positions[] = [
            		"name" => $stock["name"],
            		"price" => $stock["price"],
            		"shares" => $row["shares"],
            		"symbol" => $row["symbol"]
        		];
    		}
	}
	

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	render("sell-form.php", ["title" => "Sell Stock"]);
    }
    	
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	// delete stock
	$delete = query("DELETE FROM Portfolio WHERE id = ? AND symbol = ?", $_SESSION["id"], $row["symbol"]);
	
	// update cash
	$update = query("UPDATE users SET cash = cash + ? WHERE id = ?", $stock["price"] * $row["shares"], $_SESSION["id"]);

	$history = query("INSERT INTO history (id, symbol, shares, price, transaction) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $row["symbol"], $row["shares"], $stock["price"] * $row["shares"], SALE);

	// redirect to portfolio
	redirect("index.php");
		
    }

?>
