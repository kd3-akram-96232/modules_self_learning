package com.catalog.controller;

import jakarta.servlet.RequestDispatcher;
import jakarta.servlet.ServletConfig;
import jakarta.servlet.ServletException;
import jakarta.servlet.annotation.WebServlet;
import jakarta.servlet.http.HttpServlet;
import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpServletResponse;
import jakarta.servlet.http.HttpSession;

import java.io.IOException;
import java.util.List;

import com.catalog.dao.ProductDao;
import com.catalog.dao.ProductDaoImpl;
import com.catalog.entities.Product;

@WebServlet(value="/productServlet", loadOnStartup = 2)
public class ProductServlet extends HttpServlet {
	private static final long serialVersionUID = 1L;
	private ProductDao productDao;

	public void init(ServletConfig config) throws ServletException {
		try {
			productDao = new ProductDaoImpl();
		}catch(Exception e) {
			throw new ServletException("err in init of "+getClass(),e);
		}
	}

	public void destroy() {
		try {
			productDao.cleanUp();
		}catch(Exception e) {
			System.out.println("err in destroy" + getClass()+" "+e);
		}
	}

	
	protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
		System.out.println("Inside ProductServlet");
		try {
				long category_id = Long.parseLong(request.getParameter("categoryId"));
				List<Product> products = productDao.getAllProducts(category_id);
				
				request.setAttribute("product_list", products);
				RequestDispatcher rd = request.getRequestDispatcher("/WEB-INF/views/product.jsp");
				rd.forward(request, response);
			
			
		}catch(Exception e) {
			throw new ServletException("err in doGet "+ getClass(),e);
		}
	}

}
