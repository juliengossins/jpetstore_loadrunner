Action()
{

	web_set_sockets_option("SSL_VERSION", "TLS1.2");

	web_reg_find("Text=JPetStore Demo", 
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

	lr_start_transaction("02_Click_Category");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Product ID", 
		LAST);

	web_reg_find("Text=Name", 
		LAST);

	web_url("sm_fish.gif", 
		"URL=https://jpetstore.cfapps.io/catalog/categories/FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("02_Click_Category",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("03_Click_ProductID");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("FI-SW-01", 
		"URL=https://jpetstore.cfapps.io/catalog/products/FI-SW-01", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://jpetstore.cfapps.io/catalog/categories/FISH", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=/favicon.ico", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("03_Click_ProductID",LR_AUTO);

	lr_think_time(3);

	lr_start_transaction("04_Click_ItemID");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("EST-1", 
		"URL=https://jpetstore.cfapps.io/catalog/items/EST-1", 
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

	lr_start_transaction("05_Click_AddToCart");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_url("Add to Cart", 
		"URL=https://jpetstore.cfapps.io/cart?add&itemId=EST-1", 
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

	lr_start_transaction("06_Click_Remove");

	web_reg_find("Text=JPetStore Demo", 
		LAST);

	web_reg_find("Text=Your cart is empty.", 
		LAST);

	web_url("Remove", 
		"URL=https://jpetstore.cfapps.io/cart?remove&itemId=EST-1", 
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

	return 0;
}