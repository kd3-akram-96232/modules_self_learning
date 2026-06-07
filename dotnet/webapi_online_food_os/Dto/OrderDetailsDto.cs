namespace webapi_online_food_os.Dto
{
    public class OrderDetailsDto
    {
        public int Fid { get; set; }
        public string FoodName { get; set; }
        public int Qty { get; set; }
        public decimal Price { get; set; }
    }
}
