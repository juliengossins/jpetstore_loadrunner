AddToCart()
{
	lr_start_transaction("05_Click_AddToCart");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=CartItems",
		"LB=<a href=\"/catalog/items/",
		"RB=\">",
		"Ordinal=All",
		LAST);
	
	web_url("Add to Cart", 
		"URL=https://jpetstore.cfapps.io/cart?add&itemId={CurrentItem}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/items/EST-1", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("05_Click_AddToCart",LR_AUTO);

	lr_think_time(3);
}
