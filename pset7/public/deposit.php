<?php
	require("../includes/config.php");



    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	render("deposit-form.php", ["title" => "Deposit funds"]);
    }

    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {

	$update_cash = query("UPDATE users SET cash = cash + ? WHERE id = ?", $_POST["cash"], $_SESSION["id"]);

	redirect("index.php");

    }

?>
