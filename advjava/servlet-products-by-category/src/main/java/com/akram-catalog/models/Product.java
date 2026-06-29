package com.catalog.entities;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

//Product.java        // product_id(PK), product_name, price, stock, category_id(FK)

@AllArgsConstructor
@NoArgsConstructor
@Getter
@Setter
@ToString
public class Product {
	private long product_id;
	private String product_name;
	private double price;
	private int stock;
	private long category_id;
}
