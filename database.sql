-- Database generated with pgModeler (PostgreSQL Database Modeler).
-- pgModeler version: 1.0.0-beta1
-- PostgreSQL version: 15.0
-- Project Site: pgmodeler.io
-- Model Author: ---

-- Database creation must be performed outside a multi lined SQL file. 
-- These commands were put in this file only as a convenience.
-- 
-- object: new_database | type: DATABASE --
-- DROP DATABASE IF EXISTS new_database;
CREATE DATABASE IF NOT EXISTS instagram OWNER ${USER};
-- ddl-end --


-- object: public.users | type: TABLE --
-- DROP TABLE IF EXISTS public.users CASCADE;
CREATE TABLE public.users (
	"Id" serial NOT NULL,
	name varchar NOT NULL,
	email varchar NOT NULL,
	pwd varchar NOT NULL,
	CONSTRAINT users_pk PRIMARY KEY ("Id")
);
-- ddl-end --
ALTER TABLE public.users OWNER TO ${USER};
-- ddl-end --

-- object: public.publications | type: TABLE --
-- DROP TABLE IF EXISTS public.publications CASCADE;
CREATE TABLE public.publications (
	id serial,
	image bytea NOT NULL,
	content text NOT NULL,
	created_at date NOT NULL,
	user_id bigint

);
-- ddl-end --
ALTER TABLE public.publications OWNER TO ${USER};
-- ddl-end --

-- object: fk_user | type: CONSTRAINT --
-- ALTER TABLE public.publications DROP CONSTRAINT IF EXISTS fk_user CASCADE;
ALTER TABLE public.publications ADD CONSTRAINT fk_user FOREIGN KEY (user_id)
REFERENCES public.users ("Id") MATCH SIMPLE
ON DELETE NO ACTION ON UPDATE NO ACTION;
-- ddl-end --


