namespace k190354_Q3
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.dataGridView3 = new System.Windows.Forms.DataGridView();
            this.label1 = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.Category = new System.Windows.Forms.ComboBox();
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).BeginInit();
            this.SuspendLayout();
            // 
            // dataGridView3
            // 
            this.dataGridView3.AllowUserToDeleteRows = false;
            this.dataGridView3.AllowUserToOrderColumns = true;
            this.dataGridView3.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dataGridView3.Location = new System.Drawing.Point(238, 179);
            this.dataGridView3.Name = "dataGridView3";
            this.dataGridView3.ReadOnly = true;
            this.dataGridView3.RowTemplate.Height = 25;
            this.dataGridView3.Size = new System.Drawing.Size(254, 245);
            this.dataGridView3.TabIndex = 0;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.label1.Font = new System.Drawing.Font("Arial Black", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.label1.Location = new System.Drawing.Point(175, 58);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(384, 23);
            this.label1.TabIndex = 1;
            this.label1.Text = "Pakistan Stock Exhange Market Summary";
            this.label1.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Segoe UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button1.Location = new System.Drawing.Point(323, 150);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(75, 23);
            this.button1.TabIndex = 4;
            this.button1.Text = "Search";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Segoe UI Semibold", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point);
            this.button2.Location = new System.Drawing.Point(332, 446);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 5;
            this.button2.Text = "Refresh";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // Category
            // 
            this.Category.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.Category.Font = new System.Drawing.Font("Segoe UI", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point);
            this.Category.FormattingEnabled = true;
            this.Category.Items.AddRange(new object[] {
            "AUTOMOBILE ASSEMBLER",
            "AUTOMOBILE PARTS & ACCESSORIES",
            "CABLE & ELECTRICAL GOODS",
            "CEMENT",
            "CHEMICAL",
            "CLOSE - END MUTUAL FUND",
            "COMMERCIAL BANKS",
            "ENGINEERING",
            "EXCHANGE TRADED FUNDS",
            "FERTILIZER",
            "FOOD & PERSONAL CARE PRODUCTS",
            "FUTURE CONTRACTS",
            "GLASS & CERAMICS",
            "INSURANCE",
            "INV. BANKS / INV. COS. / SECURITIES COS.",
            "JUTE",
            "LEASING COMPANIES",
            "LEATHER & TANNERIES",
            "MISCELLANEOUS",
            "MODARABAS",
            "OIL & GAS EXPLORATION COMPANIES",
            "OIL & GAS MARKETING COMPANIES",
            "PAPER & BOARD",
            "PHARMACEUTICALS",
            "POWER GENERATION & DISTRIBUTION",
            "PROPERTY",
            "REAL ESTATE INVESTMENT TRUST",
            "REFINERY",
            "SUGAR & ALLIED INDUSTRIES",
            "SYNTHETIC & RAYON",
            "TECHNOLOGY & COMMUNICATION",
            "TEXTILE COMPOSITE",
            "TEXTILE SPINNING",
            "TEXTILE WEAVING",
            "TOBACCO",
            "TRANSPORT",
            "VANASPATI & ALLIED INDUSTRIES",
            "WOOLLEN"});
            this.Category.Location = new System.Drawing.Point(238, 110);
            this.Category.Name = "Category";
            this.Category.Size = new System.Drawing.Size(254, 23);
            this.Category.TabIndex = 6;
            this.Category.Text = "Filter by Category";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(7F, 15F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(736, 497);
            this.Controls.Add(this.Category);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.dataGridView3);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.dataGridView3)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private DataGridView dataGridView3;
        private Label label1;
        private Button button1;
        private Button button2;
        private ComboBox Category;
    }
}