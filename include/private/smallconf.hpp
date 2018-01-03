/*
** Jason Brillante "Damdoshi"
** Hanged Bunny Studio 2014-2016
**
**
** Bibliotheque Lapin
*/

#ifndef				__LAPIN_PRIVATE_SMALLCONF_HPP__
# define			__LAPIN_PRIVATE_SMALLCONF_HPP__
# include			<iomanip>
# include			<sstream>
# include			<stack>
# include			<list>

struct				Sequence;
struct				Expression;
struct				Function;

struct				SmallConf
{
  enum				Construct
    {
      PLAIN,
      ARRAY,
      MAP
    };
  Construct			construct;

  enum				Type
    {
      INTEGER,
      DOUBLE,
      STRING,
      RAWSTRING
    };

  std::map
  <std::string, SmallConf*>	nodes;
  std::vector
  <SmallConf*>			array;
  std::map<
    std::string, SmallConf*
    >::iterator			iterator;

  bool				given_name;
  std::string			name;
  std::string			address;
  mutable bool			have_value;
  mutable std::string		original_value;
  mutable double		converted;
  mutable int			converted_2;
  mutable bool			is_converted;
  static bool			create_mode;
  static std::stack<std::string> file_read;
  static std::list<std::string> file_path;
  SmallConf			*father;
  Type				last_type;
  bool				symbol;

  Sequence			*sequence;
  Function			*function;
  Expression			*expression;
  int				line;

  SmallConf			&operator=(const SmallConf			&o)
  {
    if (&o == this)
      return (*this);
    have_value = o.have_value;
    original_value = o.original_value;
    converted = o.converted;
    converted_2 = o.converted_2;
    is_converted = o.is_converted;
    last_type = o.last_type;
    return (*this);
  }

  bool				operator==(const SmallConf			&o) const;
  bool				operator!=(const SmallConf			&o) const;
  bool				operator<(const SmallConf			&o) const;
  bool				operator<=(const SmallConf			&o) const;
  bool				operator>(const SmallConf			&o) const;
  bool				operator>=(const SmallConf			&o) const;

  static bool			RecursiveCheck(const SmallConf			&a,
					       const SmallConf			&b);
  static bool			RecursiveAssign(SmallConf			&a,
						const SmallConf			&b,
						bool				hsh,
						bool				arr);

  void				SetCreateMode(bool				cm)
  {
    create_mode = cm;
  }

  std::map
  <std::string, SmallConf*>
  ::iterator			Begin(void)
  {
    return (iterator = nodes.begin());
  }
  std::map
  <std::string, SmallConf*>
  ::iterator			End(void)
  {
    return (nodes.end());
  }
  std::map
  <std::string, SmallConf*>
  ::const_iterator		Begin(void) const
  {
    return (nodes.begin());
  }
  std::map
  <std::string, SmallConf*>
  ::const_iterator		End(void) const
  {
    return (nodes.end());
  }
  std::map
  <std::string, SmallConf*>
  ::iterator			&It(void)
  {
    return (iterator);
  }
  size_t			Size(void) const
  {
    return (array.size());
  }
  size_t			NbrChild(void) const
  {
    return (nodes.size());
  }

  SmallConf			&operator[](const std::string		&str);
  SmallConf			&operator[](size_t			i);
  const SmallConf		&operator[](const std::string		&str) const;
  const SmallConf		&operator[](size_t			i) const;

  void				Remove(const std::string		&str);
  void				Remove(size_t				i);

  bool				Access(const std::string		&str) const;
  bool				Access(ssize_t				i) const;

  void				SetString(const std::string		&v,
					  bool				raw = false);
  bool				GetString(const char			**out,
					  SmallConf			*root = NULL,
					  SmallConf			*local = NULL,
					  SmallConf			*artif = NULL,
					  SmallConf			*param = NULL) const;
  void				SetInt(int				v);
  bool				GetInt(int				*v,
				       SmallConf			*root = NULL,
				       SmallConf			*local = NULL,
				       SmallConf			*artif = NULL,
				       SmallConf			*param = NULL) const;
  void				SetDouble(double			v);
  bool				GetDouble(double			*v,
					  SmallConf			*root = NULL,
					  SmallConf			*local = NULL,
					  SmallConf			*artif = NULL,
					  SmallConf			*param = NULL) const;

  void				Clear(void);

  SmallConf(void);
  ~SmallConf(void);
};

std::ostream			&operator<<(std::ostream		&os,
					    const SmallConf		&cnf);

#endif	//			__LAPIN_PRIVATE_SMALLCONF_HPP__
