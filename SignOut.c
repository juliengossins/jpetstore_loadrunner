SignOut()
{
	lr_start_transaction("04_SignOut");

	web_reg_find("Text=Sign In", 
		LAST);

	web_url("Sign Out", 
		"URL=https://jpetstore.cfapps.io/logout", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("04_SignOut",LR_AUTO);

	lr_think_time(3);
}
