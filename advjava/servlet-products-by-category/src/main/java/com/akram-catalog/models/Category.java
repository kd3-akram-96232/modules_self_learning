package com.catalog.entities;

import lombok.AllArgsConstructor;
import lombok.Getter;
import lombok.NoArgsConstructor;
import lombok.Setter;
import lombok.ToString;

//Category.java       // category_id(PK), category_name, description


@AllArgsConstructor
@NoArgsConstructor
@Setter
@Getter
@ToString
public class Category {
	private long category_id;
	private String category_name;
	private String description;
}
