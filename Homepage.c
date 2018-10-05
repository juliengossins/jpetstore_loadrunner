Homepage()
{
	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	lr_start_transaction("01_Display_Homepage");
	
	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_save_param_ex(
		"ParamName=Categories",
		"LB=href=\"/catalog/categories/",
		"RB=\" shape",
		"NotFound=warning",
		"Ordinal=All",
		SEARCH_FILTERS,
		LAST);
	
	web_url("catalog", 
		"URL=https://jpetstore.cfapps.io/catalog", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);
	
	lr_save_string(lr_paramarr_random("Categories"), "Categories_Random");
	
	lr_end_transaction("01_Display_Homepage", LR_AUTO);
}
