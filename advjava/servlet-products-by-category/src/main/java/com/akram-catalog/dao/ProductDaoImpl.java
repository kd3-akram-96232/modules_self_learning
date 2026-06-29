package com.catalog.dao;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

import com.catalog.entities.Product;
import com.catalog.utils.DBUtils;

public class ProductDaoImpl implements ProductDao{
	
	private Connection connection;
	private PreparedStatement pst1;
	
	public ProductDaoImpl() throws SQLException{
		connection=DBUtils.getConnection();
		
		pst1=connection.prepareStatement("SELECT * FROM products WHERE category_id=?");
	}

	@Override
	public void cleanUp() throws SQLException {
		if(pst1 != null) {
			pst1.close();
		}
		if(connection != null) {
			connection.close();
		}	
	}

	@Override
	public List<Product> getAllProducts(long category_id) throws SQLException {
		List<Product> products = new ArrayList<>();
		pst1.setLong(1, category_id);
		try(ResultSet rs = pst1.executeQuery()){
			while(rs.next()) {
				products.add(new Product(rs.getLong(1), rs.getString(2), rs.getDouble(3), rs.getInt(4), rs.getLong(5)));
			}
		}
		return products;
	}
	
}
