Categories()
{
	lr_start_transaction("02_Click_Category");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Product ID", 
		LAST);

	web_reg_find("Text=Name", 
		LAST);	                   
	
	web_reg_save_param_ex(
		"ParamName=Products",
		"LB=<a href=\"/catalog/products/",
		"RB=\">",
		"Ordinal=All",
		LAST);
	                   
	web_url("sm_fish.gif", 
		"URL=https://jpetstore.cfapps.io/catalog/categories/{Categories_Random}", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_save_string(lr_paramarr_random("Products"), "Products_Random");
	
	lr_end_transaction("02_Click_Category",LR_AUTO);

	lr_think_time(3);
}
