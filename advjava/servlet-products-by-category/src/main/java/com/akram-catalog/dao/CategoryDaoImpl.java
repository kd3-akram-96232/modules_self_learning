package com.catalog.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.catalog.entities.Category;
import com.catalog.utils.DBUtils;

public class CategoryDaoImpl implements CategoryDao {
	private Connection connection;
	private PreparedStatement pst1;
	
	public CategoryDaoImpl() throws SQLException{
		//get connection;
		connection=DBUtils.getConnection();
		//pst1 - get all category
		pst1=connection.prepareStatement("SELECT * FROM categories");
	}

	@Override
	public void cleanUp() throws SQLException {
		//close all psts
		if(pst1 != null) {
			pst1.close();
		}
		if(connection != null) {
			connection.close();
		}
	}

	@Override
	public List<Category> getCategoryList() throws SQLException {
		List<Category> category = new ArrayList<>();
		try(ResultSet rs = pst1.executeQuery()){
			while(rs.next()) {
				category.add(new Category(rs.getLong(1), rs.getString(2), rs.getString(3)));
			}
		}
		return category;
	}

}






















