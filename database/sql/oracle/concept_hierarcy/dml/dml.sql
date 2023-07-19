select * from location_type_master order by 1;
select * from location_conc_hier order by 1;
select location_name from location_conc_hier natural join location_type_master where LOCATION_TYPE_NAME='city';
select location_name from location_conc_hier natural join location_type_master where LOCATION_TYPE_NAME='province_or_state';
select location_name from location_conc_hier natural join location_type_master where LOCATION_TYPE_NAME='country';
select lft.location_name, rgt.location_name from location_conc_hier lft join location_conc_hier rgt on lft.parent_lch_id = rgt.location_id order by lft.parent_lch_id;