namespace webapi_online_food_os.Dto
{
    public class PlaceOrderDto
    {
        public decimal TotalAmount { get; set; }
        public List<CartItemDto> CartItems { get; set; }
    }
}