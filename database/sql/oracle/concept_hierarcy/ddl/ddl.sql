create table location_type_master
(location_type_id integer primary key, location_type_name varchar2(50), location_type_desc varchar2(100)); 
create table location_conc_hier
(location_id integer primary key, location_name varchar2(50), location_type_id integer references location_type_master(location_type_id));
ALTER TABLE location_conc_hier ADD (parent_lch_id integer REFERENCES location_conc_hier (location_id));

