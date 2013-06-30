 Possible format
 
 byte[] bytes = Encoding.UTF8.GetBytes (WebRequestPostData ("http://" + textBox1.Text + ":" + textBox2.Text, payload));

            using (MemoryStream memStream = new MemoryStream(bytes))
            {
                using (XmlReader reader = XmlReader.Create(memStream))
                {
                   
                    while (reader.Read())
                    {
                        if (reader.NodeType == XmlNodeType.Element)
                        {
                            elemName = reader.Name;
                        }
                        if (reader.NodeType == XmlNodeType.Text)
                        {
                            elemValue = reader.Value;
                        }
                        
                        listMember = elemName + " = " + elemValue;
                        Console.WriteLine(listMember);
                       
                        //listBox1.Items.Add(listMember);
                        
                    }
                    
                }
            }