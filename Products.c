Products()
{
	lr_start_transaction("05_Click_ProductID");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=Items",
		"LB=<a href=\"/catalog/items/",
		"RB=\">",
		"Ordinal=All",
		LAST);
	
	web_url("FI-SW-01", 
		"URL=https://jpetstore.cfapps.io/catalog/products/{CurrentProduct}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/categories/FISH", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("05_Click_ProductID",LR_AUTO);

	lr_think_time(3);
}
