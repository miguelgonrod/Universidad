
package tc.json;

import java.util.HashMap;
import java.util.Map;
import javax.annotation.processing.Generated;
import com.fasterxml.jackson.annotation.JsonAnyGetter;
import com.fasterxml.jackson.annotation.JsonAnySetter;
import com.fasterxml.jackson.annotation.JsonIgnore;
import com.fasterxml.jackson.annotation.JsonInclude;
import com.fasterxml.jackson.annotation.JsonProperty;
import com.fasterxml.jackson.annotation.JsonPropertyOrder;

@JsonInclude(JsonInclude.Include.NON_NULL)
@JsonPropertyOrder({
    "name",
    "id",
    "nametype",
    "recclass",
    "mass",
    "fall",
    "year",
    "reclat",
    "reclong",
    "geolocation",
    ":@computed_region_cbhk_fwbd",
    ":@computed_region_nnqa_25f4"
})
@Generated("jsonschema2pojo")
public class Meteorite {

    @JsonProperty("name")
    private String name;
    @JsonProperty("id")
    private String id;
    @JsonProperty("nametype")
    private String nametype;
    @JsonProperty("recclass")
    private String recclass;
    @JsonProperty("mass")
    private String mass;
    @JsonProperty("fall")
    private String fall;
    @JsonProperty("year")
    private String year;
    @JsonProperty("reclat")
    private String reclat;
    @JsonProperty("reclong")
    private String reclong;
    @JsonProperty("geolocation")
    private Geolocation geolocation;
    @JsonProperty(":@computed_region_cbhk_fwbd")
    private String computedRegionCbhkFwbd;
    @JsonProperty(":@computed_region_nnqa_25f4")
    private String computedRegionNnqa25f4;
    @JsonIgnore
    private Map<String, Object> additionalProperties = new HashMap<String, Object>();

    @JsonProperty("name")
    public String getName() {
        return name;
    }

    @JsonProperty("name")
    public void setName(String name) {
        this.name = name;
    }

    @JsonProperty("id")
    public String getId() {
        return id;
    }

    @JsonProperty("id")
    public void setId(String id) {
        this.id = id;
    }

    @JsonProperty("nametype")
    public String getNametype() {
        return nametype;
    }

    @JsonProperty("nametype")
    public void setNametype(String nametype) {
        this.nametype = nametype;
    }

    @JsonProperty("recclass")
    public String getRecclass() {
        return recclass;
    }

    @JsonProperty("recclass")
    public void setRecclass(String recclass) {
        this.recclass = recclass;
    }

    @JsonProperty("mass")
    public String getMass() {
        return mass;
    }

    @JsonProperty("mass")
    public void setMass(String mass) {
        this.mass = mass;
    }

    @JsonProperty("fall")
    public String getFall() {
        return fall;
    }

    @JsonProperty("fall")
    public void setFall(String fall) {
        this.fall = fall;
    }

    @JsonProperty("year")
    public String getYear() {
        return year;
    }

    @JsonProperty("year")
    public void setYear(String year) {
        this.year = year;
    }

    @JsonProperty("reclat")
    public String getReclat() {
        return reclat;
    }

    @JsonProperty("reclat")
    public void setReclat(String reclat) {
        this.reclat = reclat;
    }

    @JsonProperty("reclong")
    public String getReclong() {
        return reclong;
    }

    @JsonProperty("reclong")
    public void setReclong(String reclong) {
        this.reclong = reclong;
    }

    @JsonProperty("geolocation")
    public Geolocation getGeolocation() {
        return geolocation;
    }

    @JsonProperty("geolocation")
    public void setGeolocation(Geolocation geolocation) {
        this.geolocation = geolocation;
    }

    @JsonProperty(":@computed_region_cbhk_fwbd")
    public String getComputedRegionCbhkFwbd() {
        return computedRegionCbhkFwbd;
    }

    @JsonProperty(":@computed_region_cbhk_fwbd")
    public void setComputedRegionCbhkFwbd(String computedRegionCbhkFwbd) {
        this.computedRegionCbhkFwbd = computedRegionCbhkFwbd;
    }

    @JsonProperty(":@computed_region_nnqa_25f4")
    public String getComputedRegionNnqa25f4() {
        return computedRegionNnqa25f4;
    }

    @JsonProperty(":@computed_region_nnqa_25f4")
    public void setComputedRegionNnqa25f4(String computedRegionNnqa25f4) {
        this.computedRegionNnqa25f4 = computedRegionNnqa25f4;
    }

    @JsonAnyGetter
    public Map<String, Object> getAdditionalProperties() {
        return this.additionalProperties;
    }

    @JsonAnySetter
    public void setAdditionalProperty(String name, Object value) {
        this.additionalProperties.put(name, value);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append(Meteorite.class.getName()).append('@').append(Integer.toHexString(System.identityHashCode(this))).append('[');
        sb.append("name");
        sb.append('=');
        sb.append(((this.name == null)?"<null>":this.name));
        sb.append(',');
        sb.append("id");
        sb.append('=');
        sb.append(((this.id == null)?"<null>":this.id));
        sb.append(',');
        sb.append("nametype");
        sb.append('=');
        sb.append(((this.nametype == null)?"<null>":this.nametype));
        sb.append(',');
        sb.append("recclass");
        sb.append('=');
        sb.append(((this.recclass == null)?"<null>":this.recclass));
        sb.append(',');
        sb.append("mass");
        sb.append('=');
        sb.append(((this.mass == null)?"<null>":this.mass));
        sb.append(',');
        sb.append("fall");
        sb.append('=');
        sb.append(((this.fall == null)?"<null>":this.fall));
        sb.append(',');
        sb.append("year");
        sb.append('=');
        sb.append(((this.year == null)?"<null>":this.year));
        sb.append(',');
        sb.append("reclat");
        sb.append('=');
        sb.append(((this.reclat == null)?"<null>":this.reclat));
        sb.append(',');
        sb.append("reclong");
        sb.append('=');
        sb.append(((this.reclong == null)?"<null>":this.reclong));
        sb.append(',');
        sb.append("geolocation");
        sb.append('=');
        sb.append(((this.geolocation == null)?"<null>":this.geolocation));
        sb.append(',');
        sb.append("computedRegionCbhkFwbd");
        sb.append('=');
        sb.append(((this.computedRegionCbhkFwbd == null)?"<null>":this.computedRegionCbhkFwbd));
        sb.append(',');
        sb.append("computedRegionNnqa25f4");
        sb.append('=');
        sb.append(((this.computedRegionNnqa25f4 == null)?"<null>":this.computedRegionNnqa25f4));
        sb.append(',');
        sb.append("additionalProperties");
        sb.append('=');
        sb.append(((this.additionalProperties == null)?"<null>":this.additionalProperties));
        sb.append(',');
        if (sb.charAt((sb.length()- 1)) == ',') {
            sb.setCharAt((sb.length()- 1), ']');
        } else {
            sb.append(']');
        }
        return sb.toString();
    }

    @Override
    public int hashCode() {
        int result = 1;
        result = ((result* 31)+((this.computedRegionCbhkFwbd == null)? 0 :this.computedRegionCbhkFwbd.hashCode()));
        result = ((result* 31)+((this.year == null)? 0 :this.year.hashCode()));
        result = ((result* 31)+((this.nametype == null)? 0 :this.nametype.hashCode()));
        result = ((result* 31)+((this.mass == null)? 0 :this.mass.hashCode()));
        result = ((result* 31)+((this.reclat == null)? 0 :this.reclat.hashCode()));
        result = ((result* 31)+((this.reclong == null)? 0 :this.reclong.hashCode()));
        result = ((result* 31)+((this.computedRegionNnqa25f4 == null)? 0 :this.computedRegionNnqa25f4 .hashCode()));
        result = ((result* 31)+((this.fall == null)? 0 :this.fall.hashCode()));
        result = ((result* 31)+((this.name == null)? 0 :this.name.hashCode()));
        result = ((result* 31)+((this.recclass == null)? 0 :this.recclass.hashCode()));
        result = ((result* 31)+((this.id == null)? 0 :this.id.hashCode()));
        result = ((result* 31)+((this.additionalProperties == null)? 0 :this.additionalProperties.hashCode()));
        result = ((result* 31)+((this.geolocation == null)? 0 :this.geolocation.hashCode()));
        return result;
    }

    @Override
    public boolean equals(Object other) {
        if (other == this) {
            return true;
        }
        if ((other instanceof Meteorite) == false) {
            return false;
        }
        Meteorite rhs = ((Meteorite) other);
        return ((((((((((((((this.computedRegionCbhkFwbd == rhs.computedRegionCbhkFwbd)||((this.computedRegionCbhkFwbd!= null)&&this.computedRegionCbhkFwbd.equals(rhs.computedRegionCbhkFwbd)))&&((this.year == rhs.year)||((this.year!= null)&&this.year.equals(rhs.year))))&&((this.nametype == rhs.nametype)||((this.nametype!= null)&&this.nametype.equals(rhs.nametype))))&&((this.mass == rhs.mass)||((this.mass!= null)&&this.mass.equals(rhs.mass))))&&((this.reclat == rhs.reclat)||((this.reclat!= null)&&this.reclat.equals(rhs.reclat))))&&((this.reclong == rhs.reclong)||((this.reclong!= null)&&this.reclong.equals(rhs.reclong))))&&((this.computedRegionNnqa25f4 == rhs.computedRegionNnqa25f4)||((this.computedRegionNnqa25f4 != null)&&this.computedRegionNnqa25f4 .equals(rhs.computedRegionNnqa25f4))))&&((this.fall == rhs.fall)||((this.fall!= null)&&this.fall.equals(rhs.fall))))&&((this.name == rhs.name)||((this.name!= null)&&this.name.equals(rhs.name))))&&((this.recclass == rhs.recclass)||((this.recclass!= null)&&this.recclass.equals(rhs.recclass))))&&((this.id == rhs.id)||((this.id!= null)&&this.id.equals(rhs.id))))&&((this.additionalProperties == rhs.additionalProperties)||((this.additionalProperties!= null)&&this.additionalProperties.equals(rhs.additionalProperties))))&&((this.geolocation == rhs.geolocation)||((this.geolocation!= null)&&this.geolocation.equals(rhs.geolocation))));
    }

}
