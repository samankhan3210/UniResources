using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace k190354_Q3
{
    [Serializable, XmlRoot("Scripts")]
    public partial class Categories
    {
        [XmlElement(ElementName = "Script")]
        public string? Script { get; set; }

        [XmlElement(ElementName = "Price")]
        public float Price { get; set; }
    }
}
