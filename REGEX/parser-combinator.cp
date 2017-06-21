public static readonly Parser<JCLCommand> JCLText =
  from open in Parse.Char('$') 
  from ws1 in Parse.Char(' ').Many()
  from command in Parse.CharExcept(' ').Many().Text()
  from ws2 in Parse.Char(' ').Many()
  from content in Parse.CharExcept('"').Many().Text()
  select new JCLCommand(command, content);
 
public static readonly Parser<JCLCommand> GlobalText =
  from variablename in Parse.CharExcept('=').Many().Text()
  from ws2 in Parse.Char('=')
  from openbrack in Parse.Char('(')
  from filepath in Parse.CharExcept(')').Many().Text()
  from closebrack in Parse.Char(')')
  select new JCLCommand(variablename, filepath);
