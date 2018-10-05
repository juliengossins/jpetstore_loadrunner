Pilote()
{
	int i = 0;
	int j = 0;
	int CategoriesCount = 0;
	int ProductsCount = 0;
	int ItemsCount = 0;
	int CartItemsCount = 0;
	
	Homepage();
	CategoriesCount = lr_paramarr_len("Categories");
	if(CategoriesCount == 0)
	{
		lr_error_message("Categories Correlation is empty");
		lr_exit(LR_EXIT_VUSER, LR_FAIL);
	}
	
	Categories();
	ProductsCount = lr_paramarr_len("Products");
	
	for(i = 0; i < ProductsCount; i++)
	{
		lr_save_string(lr_paramarr_idx("Products", i+1), "CurrentProduct");
		Products();
		
		ItemsCount = lr_paramarr_len("Items");
		for(j = 0; j < ItemsCount; j++)
		{
			lr_save_string(lr_paramarr_idx("Items", j+1), "CurrentItem");
			Items();
			AddToCart();
		}
	}
	
	CartItemsCount = lr_paramarr_len("CartItems");
	for(i = 0; i < CartItemsCount; i++)
	{
		if(i == CartItemsCount - 1)
			web_reg_find("Text=Your cart is empty.", LAST);
		
		lr_save_string(lr_paramarr_idx("CartItems", i+1), "CurrentCartItem");
		RemoveFromCart();
	}
}
