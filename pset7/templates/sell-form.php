<?php	$rows = query("SELECT * FROM Portfolio WHERE id = ?", $_SESSION["id"]);
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

 ?> 


<form action="sell.php" method="post">
<p> Select what stock you want to sell </p>
    <fieldset>
        <fieldset>
        <div class="form-group">
            <select class="form-control" name="symbol">
                <option disabled selected value="">Symbol</option>
                <option value='?'><?= $row["symbol"] ?></option>            </select>
        </div>
        <div class="form-group">
            <button class="btn btn-default" type="submit">Sell</button>
        </div>
    </fieldset>
    </fieldset>
</form>

			

