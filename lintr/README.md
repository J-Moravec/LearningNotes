# Lintr

## How `lintr` parses expressions with examples

Lintr is using the [xpath](https://www.w3schools.com/xml/xpath_intro.asp) language
to search through parsed expression transformed into an XML.

First, the expression needs to be parsed using the `parse()` function, such as:

```{r}
expr = "{ x = 5 }" # simple assignment
parsed = parse(text = expr)
# expression({x = 5 })
```

Now, to see how R parsed expression, it can be processed using `getParseData()` into a data.frame or as `lintr` does, using the pkg/function `xmlparsedata::xml_parse_data()` into an XML.

To make things a little bit cleaner, use the [no_attributes](https://github.com/J-Moravec/xmlparsedata/tree/no_attributes) branch that remove attributes, then the parsed structure will be cleaner.


```{r}
xml = xmlparsedata::xml_parse_data(parsed, pretty = TRUE, attributes = FALSE)
cat(xml)
# <exprlist>
#   <expr>
#     <OP-LEFT-BRACE>{</OP-LEFT-BRACE>
#     <expr_or_assign_or_help>
#       <expr>
#         <SYMBOL>x</SYMBOL>
#       </expr>
#       <EQ_ASSIGN>=</EQ_ASSIGN>
#       <expr>
#         <NUM_CONST>5</NUM_CONST>
#       </expr>
#     </expr_or_assign_or_help>
#     <OP-RIGHT-BRACE>}</OP-RIGHT-BRACE>
#   </expr>
# </exprlist>

```

Using `xml2`, this xml can be transformed into xml-object with `xml2::read_xml()` and parsed using the `xml2::xml_find_all()` function to searh for the xpath constructs.

```{r}
xml = xml2::read_xml(xml)
xml2::xml_find_all(xml, ".//expr")
# {xml_nodeset (3)}
# [1] <expr>\n  <OP-LEFT-BRACE>{</OP-LEFT-BRACE>\n  <expr_or_assign_or_help>\n  ...
# [2] <expr>\n  <SYMBOL>x</SYMBOL>\n</expr>
# [3] <expr>\n  <NUM_CONST>5</NUM_CONST>\n</expr>
```

This shows us that `{ x = 5 }`, shows three nodes that contain expression: the whole thing between `{` and `}` is an expression, and then one expression on the left and one expression on the right side of the `=` or `EQ_ASSIGN` sign.

Compare with `x = 5`, we will hae only two expression around the `EQ_ASSIGN` node:

```{r}
xml = parse(text = "x = 5") |>
    xmlparsedata::xml_parse_data(attributes = FALSE, pretty = TRUE)
cat(xml)
# <exprlist>
#   <expr_or_assign_or_help>
#     <expr>
#       <SYMBOL>x</SYMBOL>
#     </expr>
#     <EQ_ASSIGN>=</EQ_ASSIGN>
#     <expr>
#       <NUM_CONST>5</NUM_CONST>
#     </expr>
#   </expr_or_assign_or_help>
# </exprlist>

xml |> xml2::read_xml() |>
    xml2::xml_find_all(".//expr")
# {xml_nodeset (2)}
# [1] <expr>\n  <SYMBOL>x</SYMBOL>\n</expr>
# [2] <expr>\n  <NUM_CONST>5</NUM_CONST>\n</expr>
```

Again for comparison, `x <- 5` produce yet another output.

```{r}
xml = parse(text = "x <- 5") |>
    xmlparsedata::xml_parse_data(attributes = FALSE, pretty = TRUE)
cat(xml)
# <exprlist>
#   <expr>
#     <expr>
#       <SYMBOL>x</SYMBOL>
#     </expr>
#     <LEFT_ASSIGN>&lt;-</LEFT_ASSIGN>
#     <expr>
#       <NUM_CONST>5</NUM_CONST>
#     </expr>
#   </expr>
# </exprlist>

xml |>
    xml2::read_xml() |>
    xml2::xml_find_all(".//expr")
# {xml_nodeset (3)}
# [1] <expr>\n  <expr>\n    <SYMBOL>x</SYMBOL>\n  </expr>\n  <LEFT_ASSIGN>&lt;- ...
# [2] <expr>\n  <SYMBOL>x</SYMBOL>\n</expr>
# [3] <expr>\n  <NUM_CONST>5</NUM_CONST>\n</expr>
```

You can see the differences between `=` and `<-`, `=` is parsed as `EQ_ASSIGN`, while `<-` as `LEFT_ASSIGN`.
But more importantly, there is another expression wrapped around `<-`, which is missing for `=`.
This explains the difference in behaviour, why `<-` works in implicit assignments, and why implicit assignments with `=` needs to be wrapped with `{}`.
