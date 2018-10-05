SignIn()
{
	lr_start_transaction("02_SignIn");

	web_reg_find("Text=JPetStore Demo", 
		LAST);
	
	web_reg_save_param_ex(
		"ParamName=csrf",
		"LB=_csrf\" value=\"",
		"RB=\"/>",
		"Ordinal=All",
		LAST);

	web_url("Sign In", 
		"URL=https://jpetstore.cfapps.io/login", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("02_SignIn",LR_AUTO);

	lr_think_time(3);
	
	lr_start_transaction("03_Login");
	
	web_reg_find("Text=Sign Out", 
		LAST);

	web_submit_data("login", 
		"Action=https://jpetstore.cfapps.io/login", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/login", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=_csrf", "Value={csrf_1}", ENDITEM, 
		"Name=username", "Value=jgpetstore", ENDITEM, 
		"Name=password", "Value=azertyuiop", ENDITEM, 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("03_Login",LR_AUTO);

	lr_think_time(3);
}
