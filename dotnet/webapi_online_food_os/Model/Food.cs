using System;
using System.Collections.Generic;

namespace webapi_online_food_os.Model;

public partial class Food
{
    public int Fid { get; set; }

    public string? Name { get; set; }

    public decimal? Price { get; set; }

    public string? Description { get; set; }

    public string? Image { get; set; }

    public virtual ICollection<OrderDetail> OrderDetails { get; set; } = new List<OrderDetail>();
}
