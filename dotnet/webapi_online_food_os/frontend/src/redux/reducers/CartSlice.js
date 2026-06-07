import { createSlice } from "@reduxjs/toolkit";

const CartSlice = createSlice({
    name: "cart",
    initialState: {
        cart: []
    },
    reducers: {
        clearCart: (state) => {
            state.cart = [];
        },

        incrementQuantity: (state, action) => {
            const food = state.cart.find(
                item => item.fid === action.payload.fid
            );

            if (food) {
                food.quantity += 1;
            } else {
                state.cart.push({
                    ...action.payload,
                    quantity: 1
                });
            }
        },

        decreamentQuantity: (state, action) => {
            const food = state.cart.find(
                item => item.fid === action.payload.fid
            );

            if (!food) return;

            if (food.quantity > 1) {
                food.quantity -= 1;
            } else {
                state.cart = state.cart.filter(
                    item => item.fid !== action.payload.fid
                );
            }
        },

        removeFromCart: (state, action) => {
            state.cart = state.cart.filter(
                item => item.fid !== action.payload.fid
            );
        }
    }
});

export const {
    clearCart,
    incrementQuantity,
    decreamentQuantity,
    removeFromCart
} = CartSlice.actions;

export default CartSlice.reducer;