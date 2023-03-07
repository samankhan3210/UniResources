<%@ Page Language="C#" AutoEventWireup="true" CodeBehind="WebForm1.aspx.cs" Inherits="k190354_A1_Q4.WebForm1" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head runat="server">
    <title>k190354_Q4</title>
</head>
<body>
    <form id="form1" runat="server">
        <asp:ScriptManager ID="ScriptManager1" runat="server"></asp:ScriptManager>
        <asp:UpdatePanel ID="UpdatePanel1" runat="server">
            <ContentTemplate>
                <div>
                    <asp:Label ID="Label1" runat="server" BorderStyle="None" style="margin-left: 310px; margin-top: 85px" Text="PAKISTAN STOCK EXCHANGE MARKET SUMMARY" Font-Size="35px" Font-Bold="True" Font-Underline="true" BackColor="White"></asp:Label>
                </div>
                    <asp:DropDownList ID="DropDownList1" runat="server" Height="40px" style="margin-left: 370px; margin-top: 50px; margin-bottom: 8px" Width="650px">
                        <asp:ListItem>Filter by Category</asp:ListItem>
                        <asp:ListItem>AUTOMOBILE ASSEMBLER</asp:ListItem>
                        <asp:ListItem>AUTOMOBILE PARTS & ACCESSORIES</asp:ListItem>
                        <asp:ListItem>CABLE & ELECTRICAL GOODS</asp:ListItem>
                        <asp:ListItem>CEMENT</asp:ListItem>
                        <asp:ListItem>CHEMICAL</asp:ListItem>
                        <asp:ListItem>CLOSE - END MUTUAL FUND</asp:ListItem>
                        <asp:ListItem>COMMERCIAL BANKS</asp:ListItem>
                        <asp:ListItem>ENGINEERING</asp:ListItem>
                        <asp:ListItem>EXCHANGE TRADED FUNDS</asp:ListItem>
                        <asp:ListItem>FERTILIZER</asp:ListItem>
                        <asp:ListItem>FOOD & PERSONAL CARE PRODUCTS</asp:ListItem>
                        <asp:ListItem>FUTURE CONTRACTS</asp:ListItem>
                        <asp:ListItem>GLASS & CERAMICS</asp:ListItem>
                        <asp:ListItem>INSURANCE</asp:ListItem>
                        <asp:ListItem>INV. BANKS / INV. COS. / SECURITIES COS.</asp:ListItem>
                        <asp:ListItem>JUTE</asp:ListItem>
                        <asp:ListItem>LEASING COMPANIES</asp:ListItem>
                        <asp:ListItem>LEATHER & TANNERIES</asp:ListItem>
                        <asp:ListItem>MISCELLANEOUS</asp:ListItem>
                        <asp:ListItem>MODARABAS</asp:ListItem>
                        <asp:ListItem>OIL & GAS EXPLORATION COMPANIES</asp:ListItem>
                        <asp:ListItem>OIL & GAS MARKETING COMPANIES</asp:ListItem>
                        <asp:ListItem>PAPER & BOARD</asp:ListItem>
                        <asp:ListItem>PHARMACEUTICALS</asp:ListItem>
                        <asp:ListItem>POWER GENERATION & DISTRIBUTION</asp:ListItem>
                        <asp:ListItem>PROPERTY</asp:ListItem>
                        <asp:ListItem>REAL ESTATE INVESTMENT TRUST</asp:ListItem>
                        <asp:ListItem>REFINERY</asp:ListItem>
                        <asp:ListItem>SUGAR & ALLIED INDUSTRIES</asp:ListItem>
                        <asp:ListItem>SYNTHETIC & RAYON</asp:ListItem>
                        <asp:ListItem>TECHNOLOGY & COMMUNICATION</asp:ListItem>
                        <asp:ListItem>TEXTILE COMPOSITE</asp:ListItem>
                        <asp:ListItem>TEXTILE SPINNING</asp:ListItem>
                        <asp:ListItem>TEXTILE WEAVING</asp:ListItem>
                        <asp:ListItem>TOBACCO</asp:ListItem>
                        <asp:ListItem>TRANSPORT</asp:ListItem>
                        <asp:ListItem>VANASPATI & ALLIED INDUSTRIES</asp:ListItem>
                        <asp:ListItem>WOOLLEN</asp:ListItem>
                </asp:DropDownList>
                <asp:Button ID="Button1" runat="server" Text="Search" BorderStyle="Inset" Height="40px" style="margin-left: 20px" Width="80px" OnClick="Button1_Click"/>
                <div>
                    <asp:GridView ID="GridView1" runat="server" BackColor="White" BorderColor="#999999" BorderStyle="Solid" BorderWidth="1px" CellPadding="3" ForeColor="Black" GridLines="Vertical" style="margin-left: 370px; margin-top: 20px;margin-bottom: 10px" Width="750px">
                        <AlternatingRowStyle BackColor="#CCCCCC" />
                        <FooterStyle BackColor="#CCCCCC" />
                        <HeaderStyle BackColor="Black" Font-Bold="True" ForeColor="White" />
                        <PagerStyle BackColor="#999999" ForeColor="Black" HorizontalAlign="Center" />
                        <SelectedRowStyle BackColor="#000099" Font-Bold="True" ForeColor="White" />
                        <SortedAscendingCellStyle BackColor="#F1F1F1" />
                        <SortedAscendingHeaderStyle BackColor="#808080" />
                        <SortedDescendingCellStyle BackColor="#CAC9C9" />
                        <SortedDescendingHeaderStyle BackColor="#383838" />
                    </asp:GridView>
                </div>
                <asp:Button ID="Button2" runat="server" Text="Refresh" BorderStyle="Inset" Height="40px" style="margin-left: 700px; margin-top: 5px; margin-bottom: 10px" Width="110px" OnClick="Button2_Click"/>
            </ContentTemplate>
        </asp:UpdatePanel>
    </form>
</body>
</html>
