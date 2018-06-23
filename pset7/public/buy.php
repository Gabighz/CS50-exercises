<?php
	require("../includes/config.php");

        $rows = query("SELECT * FROM Portfolio WHERE id = ?", $_SESSION["id"]);
	$stock["name"] = query("SELECT username FROM users WHERE id = ?", $_SESSION["id"]);
	$userinfo = query("SELECT cash FROM users WHERE id = ?", $_SESSION["id"]);
	$cash = $userinfo[0]["cash"];


    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	render("buy-form.php", ["title" => "Buy Stock"]);
    }
    	
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {
	$stock = lookup($_POST["symbol"]);

	if(($stock["price"] * $_POST["shares"]) < $cash)
	{

	$buy = query("INSERT INTO Portfolio (id, symbol, shares) VALUES(?, ?, ?) ON DUPLICATE KEY UPDATE shares = shares + VALUES(shares)", $_SESSION["id"],$_POST["symbol"], $_POST["shares"]);
	
	
	$update_cash = query("UPDATE users SET cash = cash - ? WHERE id = ?", $stock["price"] * $_POST["shares"], $_SESSION["id"]);

	$history = query("INSERT INTO history (id, symbol, shares, price, transaction) VALUES(?, ?, ?, ?, ?)", $_SESSION["id"], $_POST["symbol"], $_POST["shares"], $stock["price"] * $_POST["shares"], BUY);

	}	

	else if(($stock["price"] * $_POST["shares"]) > $cash)
	{

		apologize("You can't afford this");

	}
	
	redirect("index.php");
		
    }

?>
