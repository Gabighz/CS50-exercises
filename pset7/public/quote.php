<?php

    // configuration
    require("../includes/config.php");

    // if user reached page via GET (as by clicking a link or via redirect)
    if ($_SERVER["REQUEST_METHOD"] == "GET")
    {
	render("quote-form.php", ["title" => "Quote"]);
    }
    	
    else if ($_SERVER["REQUEST_METHOD"] == "POST")
    {	
	// validates the quote request
	if(lookup($_POST["symbol"]) === false)
	{
		apologize("Please enter a valid stock share");
	}
	render("../templates/quote.php", ["title" => "Quote"]);
		
    }

?>
