RemoveFromCart()
{
	lr_start_transaction("06_Click_Remove");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("Remove", 
		"URL=https://jpetstore.cfapps.io/cart?remove&itemId={CurrentCartItem}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/cart", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("06_Click_Remove",LR_AUTO);

	lr_think_time(3);
}
