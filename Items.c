Items()
{
	lr_start_transaction("04_Click_ItemID");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	
	lr_save_string(lr_paramarr_random("Items"), "Items_Random");

	web_url("EST-1", 
		"URL=https://jpetstore.cfapps.io/catalog/items/{CurrentItem}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/products/FI-SW-01", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("04_Click_ItemID",LR_AUTO);

	lr_think_time(3);
}
